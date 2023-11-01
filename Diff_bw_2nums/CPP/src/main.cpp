#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "../include/json.hpp"
#include "../include/diff_bw_2nums.hpp"
#include "../include/diff_bw_2numstest.hpp"

using json = nlohmann::json;

class Config {
public:
    std::string testcasesFile;
    std::string CppResultFile;
};

class TestCase {
public:
    int num1;
    int num2;
    int difference;
    bool result;

    void to_json(json& j) const {
        j = json{{"input", {num1, num2}}, {"output", difference}, {"result", result}};
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
            testcase.num1 = item["input1"].get<int>();
            testcase.num2 = item["input2"].get<int>();
            testcase.difference = item["output"].get<int>();
            testcases.push_back(testcase);
        }
        return testcases;
    }

    void writeResult() {
        std::ofstream outputFile("../../" + config.CppResultFile);
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
        DiffBetweenTwoNumbersTest tester;

        for (auto& testcase : util.testcases) {
            bool res = tester.test(testcase.num1, testcase.num2, testcase.difference);
            testcase.result = res;
        }

        util.writeResult();

        bool failed = false;
        for (const auto& testcase : util.testcases) {
            if (!testcase.result) {
                failed = true;
                std::cerr << "Test failed for inputs: " << testcase.num1 << ", " << testcase.num2 << std::endl;
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
