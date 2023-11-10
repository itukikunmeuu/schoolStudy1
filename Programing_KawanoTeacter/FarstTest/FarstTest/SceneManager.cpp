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
	if (m_pScene != nullptr)	// �O�̃V�[������������
	{	
		delete m_pScene;	// ������Ă���
	}
	m_pScene = nextScene;
}
