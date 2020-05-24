using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test : MonoBehaviour
{
    AudioClip microphoneInput;
    bool microphoneInitialized;
    public float sensitivity;
    public bool flapped;

    // Start is called before the first frame update
    void Start()
    {

        //init microphone input
        if (Microphone.devices.Length > 0)
        {
            var audio = GetComponent<AudioSource>();
            audio.clip = Microphone.Start(Microphone.devices[0], true, 10, 44100);
            audio.loop = true;
            float[] f = new float[audio.clip.samples * audio.clip.channels];
            audio.clip.SetData(f,0);
 
            //AudioClip audioClip = AudioClip.Create("testSound", f.Length, 1, 44100, false, false);
            audio.clip.GetData(f, 0);
            while (!(Microphone.GetPosition(null) > 0)) {}
            audio.Play();
        }   
    }

    private float[] ConvertByteToFloat(byte[] array)
    {
        float[] floatArr = new float[array.Length / 4];
        for (int i = 0; i < floatArr.Length; i++)
        {
            if (BitConverter.IsLittleEndian)
                Array.Reverse(array, i * 4, 4);
            floatArr[i] = BitConverter.ToSingle(array, i * 4) / 0x80000000;
        }
        return floatArr;
    }


    

    // Update is called once per frame
    void Update()
    {/*
        //get mic volume
        int dec = 128;
        float[] waveData = new float[dec];
        int micPosition = Microphone.GetPosition(null) - (dec + 1); // null means the first microphone
        microphoneInput.GetData(waveData, micPosition);
        //var audio = GetComponent<AudioSource>();
       
        
        // Getting a peak on the last 128 samples
        float levelMax = 0;
        for (int i = 0; i < dec; i++)
        {
            float wavePeak = waveData[i] * waveData[i];
            if (levelMax < wavePeak)
            {
                levelMax = wavePeak;
            }
        }
        float level = Mathf.Sqrt(Mathf.Sqrt(levelMax));

        if (level > sensitivity && !flapped)
        {
            Flap();
            flapped = true;
        }
        if (level < sensitivity && flapped)
        {
            flapped = false;
        }
        */
    }
}
