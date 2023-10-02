#include "storage/ValidatedReportStorage.hpp"

#include <boost/algorithm/string.hpp>
#include <chrono>
#include <ctime>
#include <iostream>
#include <stdexcept>

#include "constants/Constants.hpp"
#include "storage/DummyStorage.hpp"
#include "storage/FileStorage.hpp"
#include "storage/SQLiteStorage.hpp"

namespace {
bool validateTaxYear(const types::Report& report) {
    using Clock = std::chrono::system_clock;

    const auto now = Clock::now();
    const std::time_t now_c = Clock::to_time_t(now);
    const struct tm* parts = std::localtime(&now_c);
    const auto currentYear = 1900 + parts->tm_year;

    return report.year <= currentYear;
}
}  // namespace

namespace storage {
template <typename BaseReportStorage>
void ValidatedReportStorage<BaseReportStorage>::storeReport(
    const types::Report& report) const try {
    if (report.amount > 0.0 and validateTaxYear(report)) {
        std::string tax = report.tax;
        boost::algorithm::to_lower(tax);

        if (constants::validTaxNames.count(tax)) {
            BaseReportStorage::storeReport(report);
        }
    }
} catch (const std::exception& e) {
    std::cerr << __FILE__ << ' ' << e.what() << '\n';
}

template class ValidatedReportStorage<FileStorage>;
template class ValidatedReportStorage<SQLiteStorage>;
template class ValidatedReportStorage<DummyStorage>;
}  // namespace storage