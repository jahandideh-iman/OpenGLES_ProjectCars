#include "SideBlocker.h"
#include "GameObjectFactory.h"



SideBlocker::~SideBlocker()
{
}

void SideBlocker::OnCreation()
{
	
	

}

void SideBlocker::InitialBlocker(Size size)
{
	SetStaticFlag(true);
	GameObjectFactory::AddCollisionComponent(this, Rect(size), Phys_Blocking);
	GameObjectFactory::AddDebugRectangleComponent(this, Rect(size));
}
