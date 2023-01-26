#include <dpp/dispatcher.h>
#include <dpp/dpp.h>
#include <iostream>
#include <string>
#include <.env>

#define PROJECT_NAME "rogerium"

int main() {
    dpp::cluster bot(BOT_TOKEN);

    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "aai") {
            event.reply("Que delícia, cara!");
        }
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(dpp::slashcommand("aai", "Que delícia, cara!", bot.me.id));
        }
    });

    bot.start(dpp::st_wait);
}
