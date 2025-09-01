#pragma once
#include "Scene.h"

class ObjectManager;
class CameraSelector;
class FreeCamera;
class MainCamera;
class GameScene :public Scene
{
public:
    /// @brief SceneManager への参照を受け取ります。
// @param manager SceneManager への参照
    GameScene(SceneManager& manager);
    ~GameScene();

    /// @brief タイトルを初期化します。
    void Init() override;

    /// @brief タイトルを更新します。
    void Update() override;

    /// @brief タイトルを描画します。
    void Draw() const override;

private:
    std::shared_ptr<ObjectManager> objectMgr = nullptr;
    std::shared_ptr<CameraSelector> cameraSelector = nullptr;
    std::shared_ptr<FreeCamera> freeCamera = nullptr;
    std::shared_ptr<MainCamera> mainCamera = nullptr;
};