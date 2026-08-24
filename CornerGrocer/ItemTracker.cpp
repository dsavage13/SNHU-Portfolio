#include "ItemTracker.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>

std::string ItemTracker::normalizeItemName(const std::string& itemName) {
    std::string normalized = itemName;

    // Remove surrounding whitespace so accidental spaces do not affect a search.
    const auto firstCharacter = normalized.find_first_not_of(" \t\r\n");
    if (firstCharacter == std::string::npos) {
        return "";
    }
    const auto lastCharacter = normalized.find_last_not_of(" \t\r\n");
    normalized = normalized.substr(firstCharacter, lastCharacter - firstCharacter + 1);

    std::transform(normalized.begin(), normalized.end(), normalized.begin(),
                   [](unsigned char character) {
                       return static_cast<char>(std::tolower(character));
                   });
    normalized.front() = static_cast<char>(
        std::toupper(static_cast<unsigned char>(normalized.front())));
    return normalized;
}

bool ItemTracker::loadItems(const std::string& inputFileName) {
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        return false;
    }

    m_itemFrequencies.clear();
    std::string itemName;
    while (inputFile >> itemName) {
        ++m_itemFrequencies[normalizeItemName(itemName)];
    }
    return !inputFile.bad();
}

bool ItemTracker::createBackupFile(const std::string& outputFileName) const {
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        return false;
    }

    for (const auto& item : m_itemFrequencies) {
        outputFile << item.first << ' ' << item.second << '\n';
    }
    return outputFile.good();
}

int ItemTracker::getItemFrequency(const std::string& itemName) const {
    const auto item = m_itemFrequencies.find(normalizeItemName(itemName));
    return item == m_itemFrequencies.end() ? 0 : item->second;
}

void ItemTracker::printAllFrequencies() const {
    std::cout << "\nITEM FREQUENCIES\n" << std::string(28, '-') << '\n';
    for (const auto& item : m_itemFrequencies) {
        std::cout << std::left << std::setw(20) << item.first << item.second << '\n';
    }
}

void ItemTracker::printHistogram() const {
    std::cout << "\nPURCHASE HISTOGRAM\n" << std::string(45, '-') << '\n';
    for (const auto& item : m_itemFrequencies) {
        std::cout << std::left << std::setw(20) << item.first
                  << std::string(static_cast<std::size_t>(item.second), '*') << '\n';
    }
}
