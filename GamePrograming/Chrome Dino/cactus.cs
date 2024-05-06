using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cactus : MonoBehaviour
{
    public int Bg_speed = 10;
    public player_move player;
    // Start is called before the first frame update
    void Start(){

    }

    // Update is called once per frame
    void Update()
    {
        transform.Translate(Vector2.left * player.game_speed * Time.deltaTime, Space.Self);
        if (transform.position.x < -25)
        {
            transform.position = transform.position + new Vector3(50.0f, 00.0f, 0.0f);
            gameObject.SetActive(false);
        }
        if(player.Gameover){
            Bg_speed = player.game_speed;
        }
    }
}