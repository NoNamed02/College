using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cactus_control : MonoBehaviour
{
    public GameObject A;
    public cactus _A;
    public GameObject B;
    public cactus _B;
    public GameObject C;
    public cactus _C;
    private float timer = 0f;
    private float spawnInterval = 2f;

    void Start()
    {
        A.SetActive(false);
        B.SetActive(false);
        C.SetActive(false);
    }

    void Update()
    {
        timer += Time.deltaTime;
        if(timer >= spawnInterval){
            ActivateRandomObject();
            timer = 0f;
        }
    }

    void ActivateRandomObject()
    {
        int rand = Random.Range(0, 3);

        // 선택된 오브젝트 활성화
        switch (rand)
        {
            case 0:
                A.SetActive(true);
                break;
            case 1:
                B.SetActive(true);
                break;
            case 2:
                C.SetActive(true);
                break;
            default:
                break;
        }
    }
}
