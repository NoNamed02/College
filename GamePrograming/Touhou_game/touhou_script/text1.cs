using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using TMPro; // TextMeshPro 네임스페이스 추가

public class text1 : MonoBehaviour
{
    public TMP_Text scoreText; // TextMeshProUGUI로 변경
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        scoreText.text = "Spell Card Left : " + GameManager.instance.spellCard_count;
    }
}
