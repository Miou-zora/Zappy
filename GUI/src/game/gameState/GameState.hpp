/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** GameState
*/

#pragma once
#include "Scene.hpp"
#include "Map.hpp"
#include "GameSettings.hpp"
#include "Player.hpp"
#include "Incantation.hpp"

namespace GUI::Game {
    class GameState {
        public:
            GameState(std::shared_ptr<GUI::Graphic::Scene> scene = nullptr);
            ~GameState(void) = default;

            void update(void);
            void render(void);
            void init(void);

            void setScene(std::shared_ptr<GUI::Graphic::Scene> scene) { _scene = scene; };
            void setMap(std::shared_ptr<GUI::Game::Map> map) { _map = map; };
            void setSettings(std::shared_ptr<GUI::Game::GameSettings> settings) { _settings = settings; };

            std::shared_ptr<GUI::Graphic::Scene> getScene() { return _scene; };
            std::shared_ptr<GUI::Game::Map> getMap() { return _map; };
            std::shared_ptr<GUI::Game::GameSettings> getSettings() { return _settings; };
            std::vector<std::shared_ptr<GUI::Game::Player>> &getPlayers() { return _players; };
            std::vector<std::string> &getTeamNames() { return _teamNames; };
            std::vector<std::shared_ptr<GUI::Game::Incantation>> &getIncantations() { return _incantations; };

        private:
            void _drawTeams(void) const;

            std::shared_ptr<GUI::Graphic::Scene> _scene;
            std::shared_ptr<GUI::Game::Map> _map;
            std::shared_ptr<GUI::Game::GameSettings> _settings;
            std::vector<std::string> _teamNames;
            std::vector<std::shared_ptr<GUI::Game::Player>> _players;
            std::vector<std::shared_ptr<GUI::Game::Incantation>> _incantations;
    };
}
