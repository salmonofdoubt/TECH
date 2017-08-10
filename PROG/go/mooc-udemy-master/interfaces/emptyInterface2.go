package main

import "fmt"

type magicStore struct {
	value interface{} //empty interfaces used for generic APIs, mostly.
	name  string
}

func (ms *magicStore) SetValue(v interface{}) {
	ms.value = v
}

func (ms *magicStore) GetValue() interface{} {
	return ms.value
}

func NewMagicStore(nm string) *magicStore {
	return &magicStore{name: nm}
}

/*
func newMagicStore() *magicStore {
	return new(magicStore)
}
*/

func main() {

	m := NewMagicStore("IntStore")
	m.SetValue(3)

	if v, ok := m.GetValue().(int); ok { //type assertion
		v *= 4
		fmt.Println(v)
	}

	m = NewMagicStore("StringName")
	m.SetValue("Test")

	if v, ok := m.GetValue().(string); ok { //type assertion
		v = v + "yaya"
		fmt.Println(v)
	}
	fmt.Println(m.GetValue())
}
