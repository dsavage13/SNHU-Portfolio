#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <map>
#include <string>

// Reads grocery records and provides the frequency reports used by the menu.
class ItemTracker {
public:
    bool loadItems(const std::string& inputFileName);
    bool createBackupFile(const std::string& outputFileName) const;
    int getItemFrequency(const std::string& itemName) const;
    void printAllFrequencies() const;
    void printHistogram() const;

private:
    std::map<std::string, int> m_itemFrequencies;

    static std::string normalizeItemName(const std::string& itemName);
};

#endif
