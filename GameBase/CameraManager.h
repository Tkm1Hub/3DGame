#pragma once
#include "VirtualCameraBase.h"

class MainCamera;
class CameraSelector;
class FreeCamera;
class CameraManager
{
public:
	void Create();
	void AddCamera(std::shared_ptr<VirtualCameraBase> camera);
	void Update();

private:
	std::vector<std::shared_ptr<VirtualCameraBase>> cameras;
	std::shared_ptr<CameraSelector> cameraSelector = nullptr;
	std::shared_ptr<MainCamera> mainCamera = nullptr;
	std::shared_ptr<FreeCamera> freeCamera = nullptr;
};