package appliances

type Microwave struct {
	typeName string
}

func (mw *Microwave) Start() {
	mw.typeName = " Microwave "
}

func (mw *Microwave) GetPurpose() string {
	return "I am a " + mw.typeName + " I microwave stuff!!"

}
