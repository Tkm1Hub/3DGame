#pragma once

class IGameObject;
class MainCamera;
class FreeCamera;
enum class CameraMode
{
	Free,
	Focus,
};

class CameraSelector
{
public:
	void SetObjects(const std::vector<std::shared_ptr<IGameObject>>& objectsPtr);

	void SetFreeCamera(const std::shared_ptr<FreeCamera>& freeCameraPtr)
	{
		freeCamera = freeCameraPtr;
	}

	void SetMainCamera(const std::shared_ptr<MainCamera>& mainCameraPtr)
	{
		mainCamera = mainCameraPtr;
	}


	void Update();

private:
	CameraMode currentMode = CameraMode::Free;
	std::vector<std::shared_ptr<IGameObject>>objects;
	std::shared_ptr<MainCamera> mainCamera = nullptr;
	std::shared_ptr<FreeCamera> freeCamera = nullptr;
};