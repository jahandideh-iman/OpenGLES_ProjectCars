#include "SideBlocker.h"
#include "GameObjectFactory.h"



SideBlocker::~SideBlocker()
{
}

void SideBlocker::OnCreation()
{
	SetStaticFlag(true);
	GameObjectFactory::AddCollisionComponent(this, Rect(50, 200),Phys_Blocking);
	GameObjectFactory::AddDebugRectangleComponent(this, Rect(50, 200));

}
