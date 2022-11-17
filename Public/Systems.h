class PlayerInputSystem: public Systems
{
	void run()
	{

		//impl3
		//we need to change only player's movement
		Global.PlayerOffset2dComponent.xOffset *= Global.PlayerAxisComponent.xAxis;
		Global.PlayerOffset2dComponent.yOffset *= Global.PlayerAxisComponent.yAxis;
		
	}
};

class RenderSystem: public System
{
	void run()
	{
		//impl1
		for (auto& EntityID: Global.Entities.IDs)
		{
			//draw entity's texture
			Global.render.draw(Global.renderComponents[EntityID].texture);
		}

		//impl2
		for (auto& component: Global.renderComponents)
		{
			Global.render.draw(component.texture);
		}
	}
};

class MovementSystem: public System
{
	void run()
	{
		//impl1
		for (auto& EntityID: Global.Entities.IDs)
		{
			//run for each entity that has position component and change their location by their movement offset
			Global.positionComponents[EntityID].X *= Global.movementComponents[EntityID].xOffset;
			Global.positionComponents[EntityID].Y *= Global.movementComponents[EntityID].yOffset;
		}

		//impl2 // I think it wont work because we need to get corresponding movement component
		for (auto& component: positionComponents)
		{
			component.X *= Global.movementComponent.xOffset; //movement component has to be corresponding to Entity ID!
			component.Y *= Global.movementComponent.yOffset;
		}
	}
};
class InputSystem // "base" system. Input systems changes somehow data in components.
//trigger
//condition
//collision
//time condition input system. affects on components by checking time component and expression on it.
class timeConditionInputSystem: Systems
{
	void run()
	{
		//get time component(s) and add 10 to them
		if(Global.timeComponent.time - Global.timeComponent.prevTime > 5) //check if passed time greather than 5 sec
		{
			for (auto& id: Global.entities.timeConditionComponentEntities)
			{
				Global.timeConditionComponents[id].value += 10;
			}
		}

	}
};

//base system for all conditional systems
class In_ConditionSystem: public InputSystem
{
};
//base system for all time conditional systems
class CoIn_TimeSystem: public I_ConditionSystem
{
};

//System that checks if player lives too long
class TiCoIn_PlayerAcceleraionByTime: CI_TimeSystem
{
	void run()
	{
		if (Global.playerComponent.lifeSpan > 1.0f)
		{
			//some player related code
			Global.playerPhysicsComponent.accel -= 10.0f //decrease player's sprint acceleration after 1 hour
		}
		else
		{
			if (Global.playerComponent.lifeSpan > 2.0f)
			{
				Global.playerPhysicsComponent.accel -= 30.0f //decrease player's sprint acceleration after 2 hours
			}
		}
	}
	
};

//location condition
//kill trigger
//base system for trigger systems
class In_TriggerSystem: public InputSystem
{
};

class TrIn_PlayerTriggerDeath: public In_TriggerSystem
{
	void run()
	{
		//check if player intersect any triggers in the world
		for (auto& trigger: Global.worldTriggerComponents)
		{
			//check if trigger close enough to the player
			if(trigger.Origin < Global.playerPhysicsComponent.triggerCullingDistance)
			{
				//check if trigger intersects player
				if (trigger.collisionMesh > Global.playerPhysicsComponent.collisionMesh)
				{
					Global.playerPhysicsComponent.bPendingDeath = true;
				}
			}
			
		}
	}
}
//projectile collision
//health condition
//