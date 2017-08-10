package shieldBuilder

import "strings"

type shield struct {
	front, back, right, left bool
}

type shBuilder struct {
	code string
}

//constructor function of the Type
func NewShieldBuilder() *shBuilder {
	return new(shBuilder)
}

//type method
func (sh *shBuilder) RaiseFront() *shBuilder {
	sh.code += "F"
	return sh
}

//type method
func (sh *shBuilder) RaiseBack() *shBuilder {
	sh.code += "B"
	return sh
}

//type method
func (sh *shBuilder) RaiseLeft() *shBuilder {
	sh.code += "L"
	return sh
}

//type method
func (sh *shBuilder) RaiseRight() *shBuilder {
	sh.code += "R"
	return sh
}

//type method (Builder)
func (sh *shBuilder) Build() *shield {
	code := sh.code
	return &shield{
		front: strings.Contains(code, "F"), //create shield object based on boolean test
		back:  strings.Contains(code, "B"),
		left:  strings.Contains(code, "L"),
		right: strings.Contains(code, "R"),
	}
}
