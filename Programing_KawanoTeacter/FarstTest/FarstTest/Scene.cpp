#include "Scene.h"

Scene::Scene(SceneManager& manager): 
	m_manager(manager)//ここで初期化するとメンバ変数のアドレス確定と同時と見なされる
{
	
}
