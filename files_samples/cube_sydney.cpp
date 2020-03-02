/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#include <irrlicht/irrlicht.h>

int main(void)
{
    irr::IrrlichtDevice *device =
    irr::createDevice(irr::video::EDT_OPENGL,
    irr::core::dimension2d<irr::u32>(800, 600), 32, false, true, false, 0);
    irr::video::IVideoDriver *driver =  device->getVideoDriver();
    irr::scene::ISceneManager *sceneManager = device->getSceneManager();
    irr::scene::IAnimatedMeshSceneNode *sydney =
    sceneManager->addAnimatedMeshSceneNode(sceneManager->
    getMesh("./ressources/sydney.md2"));
    // irr::scene::IMeshSceneNode *cube =
    // sceneManager->addCubeSceneNode(10.0f, 0, -1,
    // irr::core::vector3df(0.0f, 0.0f, 20.0f));

    driver->setFog(irr::video::SColor(0, 255, 255, 255),
    irr::video::EFT_FOG_LINEAR, 20.0f, 100.0f, 0.01f, true, true);
    sydney->setMaterialTexture(0, driver->getTexture("./ressources/sydney.bmp"));
    sydney->setMD2Animation(irr::scene::EMAT_STAND);
    sydney->setMaterialFlag(irr::video::EMF_FOG_ENABLE, false);
    sydney->setMaterialFlag(irr::video::EMF_LIGHTING, false);

    device->getCursorControl()->setVisible(false);
    sceneManager->addCameraSceneNodeFPS(0, 100.0f, 0.1f, -1, 0, 5);
    while (device->run()) {
        driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));
        sceneManager->drawAll();
        driver->endScene();
    }
    device->drop();
    return 0;
}
