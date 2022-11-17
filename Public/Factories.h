
class SystemFactory
{
	class SystemBuilder
	{

	};

	enum class ESystem
	{
		PlayerInput, 
		Render,
		Movement,
		Input,
		timeConditionInput,
		In_Condition,
		CoIn_Time,
		TiCoIn_PlayerAcceleraionByTime,
		In_Trigger,
		TrIn_PlayerTriggerDeath
	}

	System* GetSystem(ESystem system)
	{
		switch (system)
		{
			case PlayerInput:
			{
				return new PlayerInputSystem();
				break;
			}
			case Render:
			{
				return new RenderSystem();
				break;
			}
			case Movement:
			{
				return new MovementSystem();
				break;
			}
			case Input:
			{
				return new InputSystem();
				break;
			}
			case timeConditionInput:
			{
				return new timeConditionInputSystem();
				break;
			}
			case In_Condition:
			{
				return new In_ConditionSystem();
				break;
			}
			case CoIn_Time:
			{
				return new CoIn_TimeSystem();
				break;
			}
			case TiCoIn_PlayerAcceleraionByTime:
			{
				return new TiCoIn_PlayerAcceleraionByTimeSystem();
				break;
			}
			case In_Trigger:
			{
				return new In_TriggerSystem();
				break;
			}
			case TrIn_PlayerTriggerDeath:
			{
				return new TrIn_PlayerTriggerDeathSystem();
				break;
			}
			default:
			{
				break;
			}
		}
	};
};
class ComponentFactory
{
	class ComponentBuilder
	{

	};
	enum class EComponent
	{
		Position2d,
		PlayerOffset2d,
		Render,
		Axis2d,
		PlayerAxis
	};

	Component* GetComponent(EComponent component)
	{
		switch(component)
		{
			case Position2d:
			{
				return new Position2dComponent();
				break;
			}
			case PlayerOffset2d:
			{
				return new PlayerOffset2dComponent();
				break;
			}
			case Render:
			{
				return new RenderComponent();
				break;
			}
			case Axis2d:
			{
				return new Axis2dComponent();
				break;
			}
			case PlayerAxis:
			{
				return new PlayerAxisComponent();
				break;
			}
			default:
			{
				break;
			}
			
		}
	};
};