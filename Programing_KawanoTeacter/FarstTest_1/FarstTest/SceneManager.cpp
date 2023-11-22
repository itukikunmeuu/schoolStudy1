#include "SceneManager.h"
#include "Scene.h"

SceneManager::~SceneManager()
{
	delete m_pScene;
}

void SceneManager::Update(Input& input)
{
	m_pScene->Update(input);
}

void SceneManager::Draw()
{
	m_pScene->Draw();
}

void SceneManager::ChangeScene(Scene* nextScene)
{
	if (m_pScene != nullptr)	// ‘O‚ÌƒV[ƒ“‚ª‚ ‚Á‚½‚ç
	{	
		delete m_pScene;	// ‰ğ•ú‚µ‚Ä‚¨‚­
	}
	m_pScene = nextScene;
}
