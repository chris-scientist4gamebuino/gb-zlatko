// author: chris-scientist
// created at: 17/10/2018
// updated at: 22/10/2018

#include "ZlatkoEngine.h"

ZlatkoEngine::ZlatkoEngine() :
  stateManager(new ZlatkoStateManager()),
  activeDefaultMenu(true),
  mainMenu(new ZlatkoDefaultMenu())
{
  initialize();
}

void ZlatkoEngine::run() {
  manageCommands();
  paint();
}

void ZlatkoEngine::manageCommands() {
  if(stateManager->isMainMenuState()) {
    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    // A moduler en fonction de votre système de menu.
    if(((ZlatkoDefaultMenu *)mainMenu)->isPlayItem()) {
      stateManager->nextState();
    } else if(((ZlatkoDefaultMenu *)mainMenu)->isAboutZlatkoItem()) {
      stateManager->setState(ZlatkoStateManager::ABOUT_ZLATKO_STATE);
    } else if(((ZlatkoDefaultMenu *)mainMenu)->isDebuggingItem()) {
      stateManager->setState(ZlatkoStateManager::DEBUG_STATE);
    }
    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  } else {
    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    // A SUPPRIMER
    if(gb.buttons.pressed(BUTTON_B)) {
      stateManager->setState(ZlatkoStateManager::MAIN_MENU_STATE);
    }
    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  }
}

void ZlatkoEngine::paint() const {
  if(stateManager->isMainMenuState()) {
    if(activeDefaultMenu) {
      mainMenu->paint();
    }
  } else if(stateManager->isGameState()) {
    gb.display.println("Votre jeu...");
    gb.display.println("Work in progress");
  } else if(stateManager->isAboutZlatkoState()) {
    ZlatkoWindow::paintAboutZlatko();
  } else if(stateManager->isDebugState()) {
    gb.display.println("Debug window");
    gb.display.println("Work in progress");
  }
}

void ZlatkoEngine::setActiveDefaultMenu(const bool isActive) {
  activeDefaultMenu = isActive;
}

void ZlatkoEngine::setDefaultMainMenu(ZlatkoAbstractMenu * aMainMenu) {
  mainMenu = aMainMenu;
}

void ZlatkoEngine::initialize() {
  // Afficher le menu par défaut
  stateManager->setState(ZlatkoStateManager::MAIN_MENU_STATE);
  // Afficher un écran de démarrage
  static const uint8_t splashscreen[] = {
    80, 64, 1, 0, 0, 0xFF, 1, 0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x88, 0x88,0x00, 0x00,0x08, 0x88,0x80, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x08,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x80,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x08,0x88, 0x88,0x80, 0x00,0x88, 0x88,0x88, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x08,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x88,0x88, 0x88,0x88, 0x08,0x88, 0x88,0x88, 0x88,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x08,0x88, 0x99,0x99, 0x99,0x99, 0x98,0x88, 0x99,0x99, 0x99,0x88, 0x88,0x00, 0x00,0x00, 0x88,0x88, 0x88,0x88, 0x88,0x89, 0x99,0x88, 0x88,0x88, 0x99,0x98, 0x88,0x00, 0x00,0x00, 0x00,0x08, 0x88,0x00, 0x00,0x00, 0x00,0x00, 0x08,0x88, 0x9a,0xaa, 0xaa,0xaa, 0x98,0x88, 0x9a,0xaa, 0xa9,0x88, 0x88,0x00, 0x00,0x08, 0x88,0x88, 0x88,0x88, 0x88,0x89, 0xa9,0x88, 0x88,0x88, 0x9a,0x98, 0x88,0x00, 0x00,0x00, 0x00,0x88, 0x88,0x80, 0x00,0x00, 0x00,0x00, 0x08,0x88, 0x99,0x99, 0x99,0x9a, 0x98,0x88, 0x99,0x9a, 0xa9,0x88, 0x88,0x00, 0x00,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x89, 0xa9,0x88, 0x88,0x88, 0x9a,0x98, 0x88,0x00, 0x00,0x00, 0x08,0x88, 0x88,0x88, 0x00,0x00, 0x00,0x00, 0x00,0x88, 0x88,0x88, 0x88,0x9a, 0x98,0x88, 0x88,0x89, 0xa9,0x88, 0x88,0x00, 0x08,0x89, 0x99,0x99, 0x98,0x88, 0x99,0x9a, 0xaa,0x99, 0x98,0x88, 0x9a,0x98, 0x88,0x88, 0x88,0x88, 0x88,0x89, 0x99,0x88, 0x80,0x00, 0x00,0x00, 0x00,0x08, 0x88,0x88, 0x88,0x9a, 0x98,0x88, 0x88,0x89, 0xa9,0x88, 0x88,0x00, 0x88,0x89, 0xaa,0xaa, 0x98,0x88, 0x9a,0xaa, 0xaa,0xaa, 0x98,0x88, 0x9a,0x98, 0x88,0x88, 0x88,0x88, 0x88,0x89, 0xa9,0x88, 0x88,0x00, 0x00,0x00, 0x00,0x08, 0x88,0x88, 0x88,0x99, 0x98,0x88, 0x88,0x89, 0xa9,0x88, 0x88,0x08, 0x88,0x89, 0x99,0xaa, 0x98,0x88, 0x99,0x9a, 0xaa,0x99, 0x98,0x88, 0x9a,0x98, 0x88,0x88, 0x88,0x88, 0x88,0x89, 0x99,0x88, 0x88,0x80, 0x00,0x00, 0x00,0x08, 0x88,0x89, 0x99,0x88, 0x88,0x88, 0x88,0x89, 0xa9,0x88, 0x88,0x88, 0x99,0x98, 0x88,0x9a, 0x98,0x88, 0x88,0x89, 0xa9,0x88, 0x88,0x88, 0x9a,0x98, 0x88,0x99, 0x98,0x88, 0x99,0x98, 0x88,0x99, 0x98,0x88, 0x00,0x00, 0x00,0x08, 0x88,0x89, 0xa9,0x88, 0x88,0x88, 0x88,0x89, 0xa9,0x88, 0x88,0x88, 0x9a,0x98, 0x88,0x9a, 0x98,0x88, 0x88,0x89, 0xa9,0x88, 0x88,0x88, 0x9a,0x98, 0x88,0x9a, 0x98,0x88, 0x9a,0x98, 0x88,0x9a, 0x98,0x88, 0x00,0x00, 0x00,0x88, 0x88,0x89, 0x99,0x88, 0x88,0x88, 0x88,0x89, 0xa9,0x88, 0x88,0x88, 0x9a,0x98, 0x88,0x9a, 0x98,0x88, 0x88,0x89, 0xa9,0x88, 0x88,0x88, 0x9a,0x98, 0x88,0x99, 0x98,0x88, 0x9a,0x98, 0x88,0x9a, 0x98,0x88, 0x00,0x00, 0x08,0x88, 0x99,0x98, 0x88,0x88, 0x88,0x88, 0x88,0x89, 0xa9,0x88, 0x88,0x88, 0x9a,0x98, 0x88,0x9a, 0x98,0x88, 0x88,0x89, 0xa9,0x88, 0x88,0x88, 0x9a,0xa9, 0x99,0x88, 0x88,0x88, 0x9a,0x98, 0x88,0x9a, 0x98,0x88, 0x00,0x00, 0x08,0x88, 0x9a,0x98, 0x88,0x88, 0x88,0x88, 0x88,0x89, 0xa9,0x88, 0x88,0x88, 0x9a,0x98, 0x88,0x9a, 0x98,0x88, 0x88,0x89, 0xa9,0x88, 0x88,0x88, 0x9a,0xaa, 0xa9,0x88, 0x88,0x88, 0x9a,0x98, 0x88,0x9a, 0x98,0x88, 0x00,0x00, 0x08,0x88, 0x9a,0x98, 0x88,0x88, 0x88,0x88, 0x88,0x89, 0xa9,0x88, 0x88,0x88, 0x99,0x98, 0x88,0x9a, 0x98,0x88, 0x88,0x89, 0x99,0x88, 0x88,0x88, 0x9a,0xa9, 0x99,0x88, 0x88,0x88, 0x99,0x98, 0x88,0x99, 0x98,0x88, 0x00,0x00, 0x08,0x88, 0x9a,0x99, 0x99,0x99, 0x98,0x88, 0x99,0x9a, 0xaa,0x99, 0x98,0x88, 0x88,0x89, 0x99,0xaa, 0x98,0x88, 0x88,0x88, 0x88,0x99, 0x98,0x88, 0x9a,0x98, 0x88,0x99, 0x98,0x88, 0x88,0x89, 0x99,0x88, 0x88,0x80, 0x00,0x00, 0x08,0x88, 0x9a,0xaa, 0xaa,0xaa, 0x98,0x88, 0x9a,0xaa, 0xaa,0xaa, 0x98,0x88, 0x88,0x89, 0xaa,0xaa, 0x98,0x88, 0x88,0x88, 0x88,0x9a, 0x98,0x88, 0x9a,0x98, 0x88,0x9a, 0x98,0x88, 0x88,0x89, 0xa9,0x88, 0x88,0x00, 0x00,0x00, 0x08,0x88, 0x99,0x99, 0x99,0x99, 0x98,0x88, 0x99,0x99, 0x99,0x99, 0x98,0x88, 0x88,0x89, 0x99,0x99, 0x98,0x88, 0x88,0x88, 0x88,0x99, 0x98,0x88, 0x99,0x98, 0x88,0x99, 0x98,0x88, 0x88,0x89, 0x99,0x88, 0x80,0x00, 0x00,0x00, 0x08,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x00,0x00, 0x00,0x00, 0x08,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x80, 0x00,0x00, 0x00,0x00, 0x00,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x80,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x08,0x99, 0x98,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x98, 0x88,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x08,0x98, 0x88,0x98, 0x98,0x89, 0x98,0x98, 0x98,0x89, 0x88,0x98, 0x98,0x89, 0x88,0x98, 0x98,0x98, 0x88,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x08,0x99, 0x88,0x99, 0x88,0x98, 0x98,0x99, 0x98,0x98, 0x98,0x98, 0x98,0x98, 0x98,0x99, 0x88,0x98, 0x98,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x08,0x98, 0x88,0x98, 0x88,0x98, 0x98,0x98, 0x98,0x99, 0x88,0x99, 0x98,0x98, 0x98,0x98, 0x88,0x99, 0x88,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x08,0x98, 0x88,0x98, 0x88,0x89, 0x98,0x98, 0x98,0x89, 0x98,0x98, 0x98,0x89, 0x88,0x98, 0x88,0x98, 0x98,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x08,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x80,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x08, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x88,0x88, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00
  };
  Image splashscreenImg = Image(splashscreen);
  gb.display.drawImage(0, 0, splashscreenImg);
  delay(5000);
}

