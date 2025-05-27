#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
struct studentdata {
    std::string first_name;
    std::string last_name;
    int grade;
    std::string subject;
    bool is_used;
};
struct hashtable {
    std::vector<studentdata> entries;
    int collision_count;
};
const int TABLE_SIZE = 100;
int computeHash(int uid, int table_size) {
    const double golden_ratio = 0.6180339887;
    double temp = uid * golden_ratio;
    return static_cast<int>(table_size * (temp - floor(temp)));
}
int getNextIndex(int start, int step, int limit) {
    return (start + step) % limit;
}
void inithashtable(hashtable* ht) {
    ht->entries.resize(TABLE_SIZE);
    for (auto& entry : ht->entries) {
        entry.is_used = false;
    }
    ht->collision_count = 0;
}
void insertEntry(hashtable* ht, int uid, const std::string& first, const std::string& last, int grade, const std::string& subject) {
    if (grade < 1 || grade > 5) {
        std::cerr << "Error: Grade must be between 1 and 5\n";
        return;
    }
    int base_idx = computeHash(uid, ht->entries.size());
    int attempt = 0;
    while (attempt < ht->entries.size()) {
        int current_idx = getNextIndex(base_idx, attempt, ht->entries.size());

        if (!ht->entries[current_idx].is_used) {
            ht->entries[current_idx] = { first, last, grade, subject, true };
            if (attempt > 0) ht->collision_count += attempt;
            return;
        }
        ++attempt;
    }
    ++ht->collision_count;
}
studentdata* findEntry(hashtable* ht, int uid) {
    int base_idx = computeHash(uid, ht->entries.size());
    int attempt = 0;

    while (attempt < ht->entries.size()) {
        int current_idx = getNextIndex(base_idx, attempt, ht->entries.size());

        if (!ht->entries[current_idx].is_used) break;

        if (computeHash(uid, ht->entries.size()) == base_idx) {
            return &ht->entries[current_idx];
        }
        ++attempt;
    }
    return nullptr;
}
int main() {
    hashtable grade_table;
    inithashtable(&grade_table);
    insertEntry(&grade_table, 1001, "Ivan", "Petrov", 5, "Mathematics");
    insertEntry(&grade_table, 1002, "Maria", "Ivanova", 4, "Physics");
    insertEntry(&grade_table, 1003, "Alexey", "Sidorov", 3, "Chemistry");
    insertEntry(&grade_table, 1004, "Olga", "Smirnova", 5, "Computer Science");
    insertEntry(&grade_table, 1005, "Dmitry", "Vasiliev", 2, "Biology");
    std::cout << "Collisions during insertion: " << grade_table.collision_count << "\n\n";
    while (true) {
        std::cout << "Enter student ID (0 to exit): ";
        int search_id;
        std::cin >> search_id;
        if (search_id == 0) break;

        studentdata* result = findEntry(&grade_table, search_id);
        if (result) {
            std::cout << "Record found:\n"
                << "Student: " << result->last_name << " " << result->first_name << "\n"
                << "Subject: " << result->subject << "\n"
                << "Grade: " << result->grade << "\n\n";
        }
        else {
            std::cout << "Record not found!\n\n";
        }
    }
    return 0;
}