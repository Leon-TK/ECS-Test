//Main

template <typename SYSTEM>
SYSTEM* GetSystem()
{
	return Global.GetSingletone(new SYSTEM());
}

template <typename T>
void RunSystem()
{
	T* system = GetSystem<T>();
	system->run();
};



class SystemsHandle
{
private:
	std::vector<Entity*> entities;

	void AddEntity(std::vector<Component*> components)
	{
		Entity* ent = new Entity();
		ent->id = Entity::Count;

		for (auto& component: components)
		{
			ent->AddEntity(component);
		}

		entities.add();
		Entity::Count++;
	};

	void Pipeline();
	{
		RunSystem<IoSystem>(); // affect to playerInputComponent
		RunSystem<PlayerInputSystem>(); // affect to playerMovementComponent by playerInputComponent
		RunSystem<AiInputSystem>();
		RunSystem<TriggerInputSystem>();
		RunSystem<ConditionInputSystem>();
		RunSystem<MovementSystem>(); // run for each simple entities that have movement component
		RunSystem<RenderSystem>(); // run for every entites that have renderComponent
	};

	void InitEntities()
	{
		using comp = std::vector<Components*>;
		std::vector<comp> Entities;

		comp entityComponents1;
		entityComponents1.Add(new Position2dComponent());
		entityComponents1.Add(new PlayerOffset2dComponent());
		entityComponents1.Add(new RenderComponent());
		Entities.addentityComponents1

		comp entityComponents2;
		entityComponents1.Add(new Position2dComponent());
		Entities.add(entityComponents2)

		for (auto& components: Entites)
		{
			AddEntity(components);
		}
	};

	void InitSystems()
	{

	};

};
//~Main

Globals global;

void main()
{

};