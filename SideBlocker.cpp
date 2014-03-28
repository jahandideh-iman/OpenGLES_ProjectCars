#include "SideBlocker.h"
#include "GameObjectFactory.h"



SideBlocker::~SideBlocker()
{
}

void SideBlocker::OnCreation()
{
	GameObjectFactory::AddCollisionComponent(this, Rect(50, 200));
	GameObjectFactory::AddDebugRectangleComponent(this, Rect(50, 200));

}
