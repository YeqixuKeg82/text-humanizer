// main.cpp — entry point. Wires config and subsystems together.

#include "texthumanizer/settings.h"
#include "texthumanizer/humanizer.h"
#include "texthumanizer/patterns.h"
#include "texthumanizer/paraphrase.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    texthumanizer::Settings settings = texthumanizer::Settings::load_default();
    texthumanizer::Humanizer humanizer(settings.store_path);
    texthumanizer::Patterns patterns(settings.store_path);
    texthumanizer::Paraphrase paraphrase(settings.store_path);
    std::fprintf(stderr, "[text-humanizer] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
