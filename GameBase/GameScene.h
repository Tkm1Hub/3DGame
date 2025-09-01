#pragma once
#include "Scene.h"

class ObjectManager;
class CameraSelector;
class FreeCamera;
class MainCamera;
class GameScene :public Scene
{
public:
    /// @brief SceneManager �ւ̎Q�Ƃ��󂯎��܂��B
// @param manager SceneManager �ւ̎Q��
    GameScene(SceneManager& manager);
    ~GameScene();

    /// @brief �^�C�g�������������܂��B
    void Init() override;

    /// @brief �^�C�g�����X�V���܂��B
    void Update() override;

    /// @brief �^�C�g����`�悵�܂��B
    void Draw() const override;

private:
    std::shared_ptr<ObjectManager> objectMgr = nullptr;
    std::shared_ptr<CameraSelector> cameraSelector = nullptr;
    std::shared_ptr<FreeCamera> freeCamera = nullptr;
    std::shared_ptr<MainCamera> mainCamera = nullptr;
};