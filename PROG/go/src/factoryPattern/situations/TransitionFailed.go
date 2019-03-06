package situations

type TransitionFailed struct {
	situation string
	text      string
}

func (tf *TransitionFailed) Start() {
	tf.situation = "TransitionFailed"
	tf.text = " You urgently need another internal gJOB (PM), even PARTTIME."
}

func (tf *TransitionFailed) GetAction() string {
	initialString := "Your are in " + tf.situation + " and you are screwed!!"
	return initialString + tf.text
}
