package situations

import "testing"

type InTransitionStruct struct {
	situationGiven string
	textGiven      string
	stringReturned string
}

func TestGetAction(t *testing.T) {
	var tests = InTransitionStruct{" InTransition ", " HEALTH, MAC.", "Your are in and you need to CODE as much as possible!!! HEALTH, MAC."}
	if tests.stringReturned != GetAction() {
		t.Error(
			"For", pair.values,
			"expected", pair.average,
			"got", v,
		)
	}
}
