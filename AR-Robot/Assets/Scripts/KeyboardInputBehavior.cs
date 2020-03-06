using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class KeyboardInputBehavior : MonoBehaviour {

	private bool anyKeyDown = false;

	// Update is called once per frame
	void Update () {
		
		if (Input.GetKeyDown (KeyCode.UpArrow)) {
			
			SendMessageBehavior.Instance.SendPacket ("f");

		} else if (Input.GetKeyDown (KeyCode.DownArrow)) {
			
			SendMessageBehavior.Instance.SendPacket ("b");

		} else if (Input.GetKeyDown (KeyCode.LeftArrow)) {

			SendMessageBehavior.Instance.SendPacket ("l");

		} else if (Input.GetKeyDown (KeyCode.RightArrow)) {

			SendMessageBehavior.Instance.SendPacket ("r");

		} else if (Input.GetKeyDown(KeyCode.W)) {

			SendMessageBehavior.Instance.SendPacket("w");

		} else if (Input.GetKeyDown (KeyCode.S)) {

			SendMessageBehavior.Instance.SendPacket("x");

		} else if (Input.GetKeyDown (KeyCode.A)) {

			SendMessageBehavior.Instance.SendPacket("a");

		} else if (Input.GetKeyDown (KeyCode.D)) {

			SendMessageBehavior.Instance.SendPacket("d");

		} 

		if (Input.anyKey) {
			
			anyKeyDown = true;

		} else if (!Input.anyKey && anyKeyDown) {

			anyKeyDown = false;
			SendMessageBehavior.Instance.SendPacket ("s");

		}
	}
}

