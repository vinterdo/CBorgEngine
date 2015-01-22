#pragma once

class gameObject;

class component
{
public:
	component(void);
	~component(void);

	virtual void draw(void) = 0;
	virtual void update(void) = 0;
	virtual void fixedUpdate(void) = 0;
	virtual void destroy(void) = 0;
	virtual void start(void) = 0;

	gameObject* getParent();
	virtual void setParent(gameObject* go);

protected:
	gameObject* parent;
};

