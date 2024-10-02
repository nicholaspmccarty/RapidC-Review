// Nicholas McCarty
// 10/2/2024
// String practice for midterm

#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <unordered_map> 
#include <istream>
#include <ostream>
#include <fstream>  // Needed for std::ifstream
#include <iostream> // For std::cerr and std::cout
#include <string> 
#include <utility>


/**
 * Exercise 1: Reverse Words in a Sentence (Difficulty 3/10)
 * Given a sentence as a string, reverse the order of words in the sentence.
 * You may assume the input will not contain any punctuation.
 *
 * @param sentence The input sentence as a string
 * @return A new string where the words are in reverse order
 */
std::string reverseWords(const std::string& sentence) {
    // TODO: Implement the logic to reverse the words in the sentence.
    std::vector<char> retVec;
    std::string ret;
    for (int i = sentence.length(); i > 0; i--) {
        retVec.push_back(sentence[i-1]);
    }

    for (auto j : retVec) {
    ret += j;  // Add the character directly
    }

    return ret;
}

/**
 * Exercise 2: Find the Longest Word (Difficulty 5/10)
 * Given a string, find and return the longest word in the string.
 * You may assume that words are separated by single spaces and no punctuation.
 *
 * @param sentence The input sentence as a string
 * @return The longest word found in the sentence
 */
std::string findLongestWord(const std::string& sentence) {
    // TODO: Implement the logic to find and return the longest word.
    std::vector<std::string> Words;
    std::string word, result;
    std::istringstream is(sentence);

    size_t max = -1;

    while (is >> word) {
        if (word.length() > max) {
            max = word.length();
        }
        Words.push_back(word);
    }
        
        for (auto j : Words) {
            if (j.length() == max) {
                result = j;
            }
        }
    return result;
}

/**
 * Exercise 3: Count Unique Words (Difficulty 6.5/10)
 * Given a string, count and return the number of unique words in the string.
 * You may assume that words are separated by single spaces and no punctuation.
 *
 * @param sentence The input sentence as a string
 * @return The number of unique words in the sentence
 */
int countUniqueWords(const std::string& sentence) {
    // TODO: Implement the logic to count the number of unique words.

    std::istringstream streamer(sentence);
    std::string result, word;
    std::unordered_map<std::string, int> umap; 
    size_t uniqueWords = 0;

    while (streamer >> word) {
        umap[word] = umap[word] + 1;
    }

    for (const auto pair : umap) {
        if (pair.second == 1) {
            uniqueWords++;
        }
    }

    return uniqueWords;
    
}

/**
 * @brief Sorts a vector of integers in ascending order using the `std::sort` algorithm.
 * 
 * This method demonstrates the importance of using the `std::sort` function, which is critical for 
 * efficient data manipulation as covered in your study guide. Sorting is a fundamental concept when 
 * working with collections of data like vectors, which is crucial in algorithm development.
 * 
 * @param vec A reference to a vector of integers.
 */
void sortVector(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());

}

/**
 * @brief Counts the occurrences of elements in an unordered_map.
 * 
 * Hash maps (unordered_map) are essential for associative data storage and retrieval, as described 
 * in the study guide. Understanding how to manipulate these maps allows for efficient storage and 
 * searching operations, which is a core C++ concept.
 * 
 * @param map An unordered_map of string keys and integer values.
 * @param key The key whose occurrences need to be counted.
 * @return The number of occurrences of the specified key.
 */
int countOccurrences(const std::unordered_map<std::string, int>& map, const std::string& key) {
    return map.count(key);

}

/**
 * @brief Reads and returns the first line from a text file.
 * 
 * File I/O operations, such as reading from a file using streams, are vital for handling external 
 * data, which is heavily emphasized in the study guide. Knowing how to perform basic I/O operations 
 * in C++ will help with tasks like benchmarking and profiling programs that rely on external data.
 * 
 * @param filename The name of the file to read from.
 * @return The first line of text from the file.
 */
std::string readFirstLineFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    std::string temp;

    if (inFile.is_open()) {
            std::getline(inFile, temp);
        while (std::getline(inFile, temp)) {
            std::cout << temp << std::endl;
        }
    }
    inFile.close();
    return temp;
}

/**
 * @brief Removes duplicate elements from a vector of integers.
 * 
 * Removing duplicates from a vector leverages C++ standard algorithms like `std::unique`, which is 
 * a key topic in your study guide under vector operations and algorithms. This method enhances memory 
 * and performance efficiency by eliminating unnecessary elements.
 * 
 * @param vec A reference to the vector of integers.
 */
void removeDuplicates(std::vector<int>& vec) {
    // We will leverage the STD library and the function unique to simplify this process.
    std::sort(vec.begin(), vec.end());
    auto j = std::unique(vec.begin(), vec.end());

    // Remove empty elements
    vec.erase(j, vec.end());

    // Displaying for debugging purposes
    std::cout << "Printing the vector after removing duplicates" << std::endl;
    for (const auto& j : vec) {
        std::cout << j << " " << std::endl;
    }
}

/**
 * @brief Finds both the minimum and maximum values in a vector of integers.
 * 
 * Understanding how to find the minimum and maximum values in a vector is essential for optimizing 
 * performance when dealing with large datasets. This method utilizes standard algorithms, which are 
 * important for reducing runtime in complex operations.
 * 
 * @param vec A vector of integers.
 * @return A pair where first is the minimum and second is the maximum value.
 */
std::pair<int, int> findMinMax(const std::vector<int>& vec) {
    std::vector<int> sortedVec = vec;
    std::sort(sortedVec.begin(), sortedVec.end());

    std::pair<int, int> ret;
    ret.first = vec.front();
    ret.second = vec.back();

    return ret;
}

/**
 * @brief Converts an integer to a std::string using string streams.
 * 
 * This problem addresses the importance of converting data types, which is covered in the study guide 
 * under strings and data manipulation. Converting integers to strings is a fundamental operation when 
 * interfacing with input/output streams or generating formatted outputs.
 * 
 * @param num The integer to convert.
 * @return The integer as a string.
 */
std::string intToString(int num) {

}




int main() {

    std::string sentence1 = "apple banana cherry apple";
    std::cout << "Test 1: " << countUniqueWords(sentence1) << std::endl; // Expected output: 2

    // Test case 2: Sentence with all unique words
    std::string sentence2 = "one two three four five";
    std::cout << "Test 2: " << countUniqueWords(sentence2) << std::endl; // Expected output: 5

    // Test case 3: Sentence with repeated words
    std::string sentence3 = "repeat repeat repeat one";
    std::cout << "Test 3: " << countUniqueWords(sentence3) << std::endl; // Expected output: 1

    // Test case 4: Empty string
    std::string sentence4 = "";
    std::cout << "Test 4: " << countUniqueWords(sentence4) << std::endl; // Expected output: 0

    // Test case 5: Sentence with mixed casing
    std::string sentence5 = "Apple apple banana";
    std::cout << "Test 5: " << countUniqueWords(sentence5) << std::endl; // Expected output: 2

    std::vector<int> damned;
    damned.push_back(4);
    damned.push_back(77);
    damned.push_back(44);
    damned.push_back(33);
    damned.push_back(44);
    damned.push_back(33);

    std::cout << "Test 6: This is in reference to testing removeDuplicates with std::unique and vec.erase()" << std::endl;
    removeDuplicates(damned);



    return 0;
}
