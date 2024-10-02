// Nicholas McCarty
// 10/2/2024
// String practice for midterm

#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <unordered_map> 


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



    return 0;
}
