#include "storage/FileStorage.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>

namespace storage {

std::optional<std::ofstream> FileStorage::open() const try {
    // TODO: pass logs.txt path as a command line argument
    std::ofstream file("logs.txt", std::ios::app);

    if (!file.is_open()) {
        file.open("logs.txt", std::ios::app);
    }

    if (file.is_open()) {
        return file;
    } else {
        std::cerr << "Error opening or creating logs.txt file." << std::endl;
        return std::nullopt;
    }
} catch (const std::exception& e) {
    std::cerr << __FILE__ << ' ' << e.what() << '\n';
    return std::nullopt;
}

void FileStorage::storeReport(const types::Report& report) const try {
    std::optional<std::ofstream> fileOpt = open();

    if (!fileOpt) {
        return;
    }

    std::ofstream& file = *fileOpt;

    file << "Payer: " << report.payer << "\n";
    file << "Tax Type: " << report.tax << "\n";
    file << "Amount: " << report.amount << "\n";
    file << "Year: " << report.year << "\n";
    file << "-----------------\n";
    file.close();
} catch (const std::exception& e) {
    std::cerr << __FILE__ << ' ' << e.what() << '\n';
}
}  // namespace storage
