#include "configs/StartupConfig.hpp"

#include <boost/program_options.hpp>
#include <iostream>

namespace po = boost::program_options;

std::optional<const StartupConfig> optionsToStartupConfig(int argc,
                                                          char* argv[]) {
    po::options_description desc("Allowed options");

    // clang-format off
    desc.add_options()
        ("help", "Produce help message")
        ("port", po::value<std::uint16_t>(), "Set server port")
        ("rf", po::value<types::ReportFormat>(), "Set tax report format (json, xml or yaml)")
        ("sf", po::value<types::StorageFormat>(), "Set logs storage format (txt, sqlite or -)");
    // clang-format on

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return std::nullopt;
    }

    return StartupConfig{vm["port"].as<std::uint16_t>(),
                         vm["rf"].as<types::ReportFormat>(),
                         vm["sf"].as<types::StorageFormat>()};
}