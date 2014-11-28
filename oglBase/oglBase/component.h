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
	void setParent(gameObject* go);

private:
	gameObject* parent;
};

