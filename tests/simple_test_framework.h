#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <functional>

class SimpleTest {
private:
    static int total_tests;
    static int passed_tests;
    static std::vector<std::string> failed_tests;
    
public:
    static void assert_equal(const std::string& test_name, int expected, int actual) {
        total_tests++;
        if (expected == actual) {
            passed_tests++;
            std::cout << "[PASS] " << test_name << std::endl;
        } else {
            failed_tests.push_back(test_name);
            std::cout << "[FAIL] " << test_name 
                      << " - Expected: " << expected 
                      << ", Got: " << actual << std::endl;
        }
    }
    
    static void assert_equal(const std::string& test_name, const std::string& expected, const std::string& actual) {
        total_tests++;
        if (expected == actual) {
            passed_tests++;
            std::cout << "[PASS] " << test_name << std::endl;
        } else {
            failed_tests.push_back(test_name);
            std::cout << "[FAIL] " << test_name 
                      << " - Expected: \"" << expected 
                      << "\", Got: \"" << actual << "\"" << std::endl;
        }
    }
    
    static void assert_true(const std::string& test_name, bool condition) {
        total_tests++;
        if (condition) {
            passed_tests++;
            std::cout << "[PASS] " << test_name << std::endl;
        } else {
            failed_tests.push_back(test_name);
            std::cout << "[FAIL] " << test_name << " - Expected true, got false" << std::endl;
        }
    }
    
    static void assert_false(const std::string& test_name, bool condition) {
        total_tests++;
        if (!condition) {
            passed_tests++;
            std::cout << "[PASS] " << test_name << std::endl;
        } else {
            failed_tests.push_back(test_name);
            std::cout << "[FAIL] " << test_name << " - Expected false, got true" << std::endl;
        }
    }
    
    static void run_test(const std::string& test_name, std::function<void()> test_func) {
        std::cout << "\n--- Running " << test_name << " ---" << std::endl;
        try {
            test_func();
        } catch (const std::exception& e) {
            total_tests++;
            failed_tests.push_back(test_name);
            std::cout << "[FAIL] " << test_name << " - Exception: " << e.what() << std::endl;
        }
    }
    
    static void print_summary() {
        std::cout << "\n=== Test Summary ===" << std::endl;
        std::cout << "Total tests: " << total_tests << std::endl;
        std::cout << "Passed: " << passed_tests << std::endl;
        std::cout << "Failed: " << (total_tests - passed_tests) << std::endl;
        
        if (!failed_tests.empty()) {
            std::cout << "\nFailed tests:" << std::endl;
            for (const auto& test : failed_tests) {
                std::cout << "  - " << test << std::endl;
            }
        }
        
        std::cout << "Success rate: " 
                  << (total_tests > 0 ? (passed_tests * 100.0 / total_tests) : 0) 
                  << "%" << std::endl;
    }
    
    static void reset() {
        total_tests = 0;
        passed_tests = 0;
        failed_tests.clear();
    }
};

// Static member definitions
int SimpleTest::total_tests = 0;
int SimpleTest::passed_tests = 0;
std::vector<std::string> SimpleTest::failed_tests;