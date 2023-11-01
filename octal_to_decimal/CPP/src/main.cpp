#include "../include/json.hpp"
#include "../include/oct_to_dec.hpp"
#include "../include/oct_to_dectest.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using json = nlohmann::json;

class Config {
public:
    std::string testcasesFile;
    std::string CppResultFile;
};

class TestCase {
public:
    std::string octal;
    int decimalValue;
    bool result;

    void to_json(json& j) const {
        j = json{{"input", octal}, {"output", decimalValue}, {"result", result}};
    }
};

json serialize(std::vector<TestCase> testcases) {
    json outputJson = json::array();
    for (const auto& testcase : testcases) {
        json j;
        testcase.to_json(j);
        outputJson.push_back(j);
    }
    return outputJson;
}

class Util {
public:
    std::vector<TestCase> testcases;
    Config config;

    Util() {
        config = readConfig();
        testcases = readTestcases();
    }

    Config readConfig() {
        std::ifstream configFile("../../conf/config.json");
        if (!configFile.is_open()) {
            throw std::runtime_error("Error: Unable to open config.json");
        }

        json configJson;
        configFile >> configJson;
        configFile.close();
        Config config;
        config.testcasesFile = configJson["testcasesFile"];
        config.CppResultFile = configJson["CppResultFile"];
        return config;
    }

    std::vector<TestCase> readTestcases() {
        std::ifstream testcaseFile("../../" + config.testcasesFile);
        if (!testcaseFile.is_open()) {
            throw std::runtime_error("Error: Unable to open testcases.json");
        }

        json j;
        testcaseFile >> j;
        testcaseFile.close();

        std::vector<TestCase> testcases;
        for (const auto& item : j) {
            TestCase testcase;
            testcase.octal = item["input"].get<std::string>();
            testcase.decimalValue = item["output"].get<int>();
            testcases.push_back(testcase);
        }
        return testcases;
    }

    void writeResult() {
        std::ofstream outputFile("../../" +config.CppResultFile);
        json outputJson = serialize(testcases);
        if (outputFile.is_open()) {
            outputFile << std::setw(4) << outputJson;
            outputFile.close();
            std::cout << "Data written to " << config.CppResultFile << std::endl;
        } else {
            std::cerr << "Failed to open " << config.CppResultFile << " for writing." << std::endl;
        }
    }
};

int main() {
    try {
        Util util;
        OctToDecimalTester tester;

        for (auto& testcase : util.testcases) {
            bool res = tester.testOctToDecimal(testcase.octal, testcase.decimalValue);
            testcase.result = res;
        }

        util.writeResult();

        bool failed = false;
        for (const auto& testcase : util.testcases) {
            if (!testcase.result) {
                failed = true;
                std::cerr << "Test failed for input: " << testcase.octal << std::endl;
            }
        }

        if (failed) {
            throw std::runtime_error("Some testcases failed");
        }

        std::cout << "All testcases passed" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
