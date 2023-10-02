#pragma once

#include <sqlite3/sqlite3.h>

#include "storage/IReportStorage.hpp"

namespace storage {
class SQLiteStorage : public IReportStorage {
   public:
    void storeReport(const types::Report& report) const override;

   private:
    std::optional<sqlite3*> openDatabase() const;
    bool createReportsTable(sqlite3* db) const;
    bool insertReport(sqlite3* db, const types::Report& report) const;
};
}  // namespace storage
