#include "Cappuccino/Application.h"

#include "GameScene.h"
#include "MenuScene.h"
#include "CreditsScene.h"

using Application = Cappuccino::Application;
using FontManager = Cappuccino::FontManager;
using Mesh        = Cappuccino::Mesh;
using Shader      = Cappuccino::Shader;
using SoundSystem = Cappuccino::SoundSystem;
using Texture     = Cappuccino::Texture;


#pragma region PROGRAM SETTINGS

constexpr GLuint  SCR_WIDTH = 1600;
constexpr GLuint  SCR_HEIGHT = 1200;
constexpr GLchar* SCR_TITLE = "Too Many Characters";

#pragma endregion

// This piece of code was given to us by Shawn Matthews
// Auto-magically changes OpenGL to use the high performance GPU to render rather than the iGPU
// (for dual GPU systems)
extern "C" {
	__declspec(dllexport) unsigned long NvOptimusEnablement = 0x01;
	__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 0x01;
}

int main() {

	if(!Application::isInstantiated()) {
		Application* application = new Application(SCR_WIDTH, SCR_HEIGHT, SCR_TITLE);
		application->init();		

		application->_clearColour.x = 125.f;
		application->_clearColour.y = 18.f;
		application->_clearColour.z = 255.f;

		application->_clearColour /= 255.f;

		FontManager::setDefaultPath("./Assets/Fonts/");
		Mesh::setDefaultPath("./Assets/Meshes/");
		Shader::setDefaultPath("./Assets/Shaders/");
		SoundSystem::setDefaultPath("./Assets/Sounds/");
		Texture::setDefaultPath("./Assets/Textures/");

		FontManager::loadTypeFace("comic.ttf");


		GameScene* game = new GameScene(false);
		CreditsScene* credits = new CreditsScene(false);
		MenuScene* GiuliaIsTheBest = new MenuScene(true);
		GiuliaIsTheBest->init();
		

		application->run();
		delete application;
	}

	return 0;

}
