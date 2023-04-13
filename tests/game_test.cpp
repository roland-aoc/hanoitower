#include <gtest/gtest.h>

#include "../game/game.h"
#include "../game/util.h"
#include "../game/util.cpp"
#include "../config.h"

#include <spdlog/spdlog.h>

#include <stdexcept>

using std::invalid_argument;
using std::string;

class GameTest : public ::testing::Test {
protected:
    up<Game> game = nullptr;
    up<Board> board = nullptr;

    static void SetUpTestSuite() {
        config::LogManager::init();
    }

    void SetUp() override {
        game = make_unique<Game>(2);
        board = make_unique<Board>();
    }

    void TearDown() override {
    }
};

TEST_F(GameTest, Play) {
    ASSERT_EQ(7, game->playWithScore("me", 3));
}

TEST_F(GameTest, PlayWithVarN) {
    int N = 9;
    ASSERT_EQ(2 << N - 1, game->playWithScore("me", N));
}

TEST_F(GameTest, TooDifficult) {
    ASSERT_THROW(game->playWithScore("me", 11), invalid_argument);
}

TEST_F(GameTest, TimeIsUp) {
    int startMillis = 1;
    int maxMins = 5;
    int advancedMins = maxMins++;
    game = make_unique<Game>(make_unique<Board>(), maxMins, make_unique<UtilMock>(startMillis, advancedMins * 60 * 10000));
    game->setUp(8);
    ASSERT_TRUE(game->timeIsUp());
}
