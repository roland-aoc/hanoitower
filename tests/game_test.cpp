#include <gtest/gtest.h>
#include <string>

#include "../game/game.h"
#include "../config.h"

#include <spdlog/spdlog.h>

#include <stdexcept>

using std::invalid_argument;
using std::string;

class GameTest : public ::testing::Test {
protected:
    Game* game = nullptr;
    Board* board = nullptr;

    static void SetUpTestSuite() {
        config::LogManager::init();
    }

    void SetUp() override {
        game = new Game;
        board = new Board;
    }

    void TearDown() override {
    }
};

TEST_F(GameTest, Play) {
    ASSERT_EQ(0, game->playWithScore("me", 10));
}

TEST_F(GameTest, TooDifficult) {
    ASSERT_THROW(game->playWithScore("me", 11), invalid_argument);
}

TEST_F(GameTest, MovesCorrect) {
    board->startingPos(8);
    ASSERT_TRUE(board->moveFromFirstRod('2'));
    ASSERT_FALSE(board->moveFromFirstRod('1'));
    ASSERT_FALSE(board->moveFromSecondRod('2'));
    ASSERT_FALSE(board->moveFromThirdRod('3'));
}
