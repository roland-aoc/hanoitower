#include <gtest/gtest.h>
#include <string>

#include "../game/game.h"
#include "../config.h"

#include <spdlog/spdlog.h>

using std::string;

class GameTest : public ::testing::Test {
protected:
    
    static void SetUpTestSuite() {
        config::LogManager::init();
    }

    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(GameTest, Play) {
    ASSERT_EQ(.0, .0);
}