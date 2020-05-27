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
            var audio2 = GetComponent<AudioSource>();
            audio.clip = Microphone.Start(Microphone.devices[0], true, 10, 5000);
            audio.loop = true;
            byte[] bytedata = new byte[audio.clip.samples * audio.clip.channels];
            //send

            //retrieve
            float[] f = ConvertByteToFloat(bytedata);
            audio2.clip.GetData(f, 0);
            while (!(Microphone.GetPosition(null) > 0)) {}
            audio2.Play();
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
    {
    }
}
