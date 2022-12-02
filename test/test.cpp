#include "gtest/gtest.h"
#include "SDL.h"
#include "SDL_image.h"
#include "../headers/window.h"
#include "../headers/bird.h"

TEST(WindowClass, constructor)
{
    int screenWidth = 30;
    int screenHeight = 40;
    Window window("Title", screenWidth, screenHeight);
    EXPECT_EQ(window.getTitle(), "Title");
    EXPECT_EQ(window.getWidth(), 30);
    EXPECT_EQ(window.getHeight(), 40);
    if (!window.getStatus())
    {
        EXPECT_EQ(window.isClosed(), true);
    }
    else
    {
        EXPECT_EQ(window.isClosed(), false);
    }
}

TEST(WindowClass, invalidConstructor)
{
    int screenWidth = -30;
    int screenHeight = 40;
    Window *window1 = new Window("Title", screenWidth, screenHeight);
    screenHeight = -40;
    Window *window2 = new Window("title", screenWidth, screenHeight);
    screenWidth = -30;
    Window *window3 = new Window("title", screenWidth, screenHeight);
    EXPECT_EQ(window1->isClosed(), true);
    EXPECT_EQ(window2->isClosed(), true);
    EXPECT_EQ(window3->isClosed(), true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}