#include "storage/SQLiteStorage.hpp"

#include <iostream>
#include <sstream>

namespace storage {

std::optional<sqlite3*> SQLiteStorage::openDatabase() const try {
    sqlite3* db;

    if (sqlite3_open("logs.sqlite", &db) != SQLITE_OK) {
        std::cerr << "Error opening or creating SQLite database: "
                  << sqlite3_errmsg(db) << std::endl;
        return std::nullopt;
    }

    if (!db) {
        std::cerr << "SQLite database is not open." << std::endl;
        return std::nullopt;
    }

    return db;
} catch (const std::exception& e) {
    std::cerr << __FILE__ << ' ' << e.what() << '\n';
    return std::nullopt;
}

bool SQLiteStorage::createReportsTable(sqlite3* db) const try {
    // clang-format off
    const char* createTableSQL =
        "CREATE TABLE IF NOT EXISTS reports ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "payer TEXT NOT NULL,"
        "tax_type TEXT NOT NULL,"
        "amount REAL NOT NULL,"
        "year INTEGER NOT NULL"
        ");";
    // clang-format on
    char* errorMsg = nullptr;

    int result = sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errorMsg);

    if (result != SQLITE_OK) {
        std::cerr << "Error creating the 'reports' table: " << errorMsg
                  << std::endl;
        sqlite3_free(errorMsg);
        return false;
    }

    return true;
} catch (const std::exception& e) {
    std::cerr << __FILE__ << ' ' << e.what() << '\n';
    return false;
}

bool SQLiteStorage::insertReport(sqlite3* db, const types::Report& report) const
    try {
    std::stringstream query;
    // clang-format off
    query << "INSERT INTO reports (payer, tax_type, amount, year) VALUES ('"
          << report.payer << "', '"
          << report.tax << "', "
          << report.amount << ", "
          << report.year << " );";
    // clang-format on
    char* errorMsg = nullptr;

    int result =
        sqlite3_exec(db, query.str().c_str(), nullptr, nullptr, &errorMsg);

    if (result != SQLITE_OK) {
        std::cerr << "Error inserting data into SQLite database: " << errorMsg
                  << std::endl;
        sqlite3_free(errorMsg);
        return false;
    }

    return true;
} catch (const std::exception& e) {
    std::cerr << __FILE__ << ' ' << e.what() << '\n';
    return false;
}

void SQLiteStorage::storeReport(const types::Report& report) const try {
    std::optional<sqlite3*> dbOpt = openDatabase();

    if (!dbOpt) {
        return;
    }

    sqlite3* db = *dbOpt;

    if (!createReportsTable(db)) {
        sqlite3_close(db);
        return;
    }

    if (!insertReport(db, report)) {
        sqlite3_close(db);
        return;
    }

    sqlite3_close(db);
} catch (const std::exception& e) {
    std::cerr << __FILE__ << ' ' << e.what() << '\n';
    return;
}
}  // namespace storage
