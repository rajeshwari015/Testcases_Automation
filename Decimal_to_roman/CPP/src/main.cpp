#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "../include/json.hpp"
#include "../include/dec_to_roman.hpp"
#include "../include/dec_to_romantest.hpp"

using json = nlohmann::json;

class Config {
public:
    std::string testcasesFile;
    std::string CppResultFile;
};

class TestCase {
public:
    int decimal; // Change the data type to int for numeric values
    std::string roman;
    bool result;

    void to_json(json& j) const {
        j = json{{"input", decimal}, {"output", roman}, {"result", result}};
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
        std::ifstream configFile;
        configFile.open("../../conf/config.json");
        json configJson;
        configFile >> configJson;
        configFile.close();
        Config config;
        config.testcasesFile = configJson["testcasesFile"];
        config.CppResultFile = configJson["CppResultFile"];
        return config;
    }

    std::vector<TestCase> readTestcases() {
        std::ifstream testcaseFile;
        testcaseFile.open("../../" + config.testcasesFile);
        json j;
        testcaseFile >> j;
        testcaseFile.close();

        std::vector<TestCase> testcases;
        for (int i = 0; i < j.size(); i++) {
            TestCase testcase;
            if (j[i]["input"].is_number()) {
                // Handle number input as integers
                testcase.decimal = j[i]["input"].get<int>();
            } else if (j[i]["input"].is_string()) {
                // Handle string input (if needed)
                // testcase.decimal = std::stoi(j[i]["input"].get<std::string>());
            } else {
                throw std::runtime_error("Invalid input format in testcases.json");
            }
            testcase.roman = j[i]["output"].get<std::string>();
            testcases.push_back(testcase);
            std::cout << "Input: " << testcase.decimal << ", Expected Output: " << testcase.roman << std::endl;
        }
        return testcases;
    }

    void writeResult() {
        std::ofstream outputFile;
        outputFile.open("../../" + config.CppResultFile);
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
        bool failed = false;
        DecimalToRomanTester tester;

        for (auto& testcase : util.testcases) {
            bool res = tester.testIntToRoman(testcase.decimal, testcase.roman);
            testcase.result = res;
            if (!res) {
                failed = true;
            }
        }

        util.writeResult();

        if (failed) {
            throw std::runtime_error("Test failed");
        }

        std::cout << "All test cases passed" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
