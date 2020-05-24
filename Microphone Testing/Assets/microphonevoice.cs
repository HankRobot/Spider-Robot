using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class microphonevoice : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        AudioSource audio = GetComponent<AudioSource>();
        audio.clip = Microphone.Start("Built-in Microphone", true, 10, 44100);
        audio.Play();
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
