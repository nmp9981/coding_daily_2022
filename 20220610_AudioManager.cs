using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//사운드 정보를 담는 클래스
[System.Serializable]//인스펙터 창에서 수정 가능하게
public class Sound
{
    public string name;
    public AudioClip clip;
}
public class AudioManager : MonoBehaviour
{
    public static AudioManager instance;

    [SerializeField] Sound bgm = null;
    [SerializeField] Sound[] sfx = null;

    [SerializeField] AudioSource bgmPlayer = null;//1개만
    [SerializeField] AudioSource[] sfxPlayer = null;//여러개 재생(배열로 구현)

    void Start()
    {
        instance = this;
    }
    public void PlayBGM(string p_bgmName)
    {
        if(bgm.name == p_bgmName)
        {
            bgmPlayer.clip = bgm.clip;
            bgmPlayer.Play();//재생
        }
    }
    
    public void PlaySFX(string p_sfxName)
    {
        for (int i = 0; i < sfx.Length; i++)//sfx이 일치하는지 검사
        {
            if (sfx[i].name == p_sfxName)//sfx이 같으면
            {
                for(int j = 0; j < sfxPlayer.Length; j++)//재생중이지 않은 sfx를 찾음
                {
                    if (!sfxPlayer[j].isPlaying)
                    {
                        sfxPlayer[j].clip = sfx[i].clip;
                        sfxPlayer[j].Play();//재생
                        return;//재생하면 더 이상 반복문을 실행할 이유가 없음
                    }
                }
                return;
            }
        }
    }
}
