using UnityEngine;
using System.Collections;

public class fairy_circle_bullet : MonoBehaviour
{
    public GameObject bulletPrefab; // 생성할 총알 프리팹
    public GameObject item;
    public GameObject coin;
    public float fixedRotationSpeed = 10f; // 일정한 회전 속도
    //private float rotationSpeed = 10f;
    private float bulletAngle = 0f;
    private Animator anim;
    private BoxCollider2D box;
    //public GameManager manager;
    [SerializeField] private float speed = 5.0f;

    private bool is_hit = false;

    Vector3 unit;
    void Start(){
        anim = GetComponent<Animator>();
    }

    void Update()
    {
        if(gameObject.transform.position.y >= -0.24){
            transform.Translate(Vector3.down * Time.deltaTime * speed);
        }
        // 회전 속도를 고정된 값으로 설정
        //rotationSpeed = fixedRotationSpeed;

        // 회전 각도를 업데이트합니다.
        bulletAngle += 1f;

        if(Time.frameCount % 5 == 0)
        {
            Vector3 bulletDirection = Quaternion.Euler(0, 0, bulletAngle + 120f) * transform.up;
            if(is_hit == false)
                Instantiate(bulletPrefab, transform.position, Quaternion.LookRotation(Vector3.forward, bulletDirection));
        }
    }
    
    /*
    private void OnCollisionEnter2D(Collision2D collision)
    {
        Debug.Log("hit!!!!!!!!!!!!!!");
        if (collision.gameObject.CompareTag("player_bullet"))
        {
            box.enabled = false;
            manager.score += 100;
            anim.Play("fairy_die");
        }
    }
    */
    
    
    private void OnTriggerEnter2D(Collider2D collision)
    {
        //GameObject gameM = GameObject.FindGameObjectWithTag("GameM");
        if (collision.gameObject.CompareTag("player_bullet") && is_hit == false)
        {
            anim.SetInteger("is_hit_ani",1);
            //manager.score += 100;
            GameManager.instance.score += 100;
            GameManager.instance.boss_spwan += 1;
            Debug.Log("hit!!!!!!!!!!!!!!");
            //anim.Play("fairy_die");
            StartCoroutine(die());
            is_hit = true;
        }
        if (collision.gameObject.CompareTag("spellcard"))
        {
            AudioSource sound = GetComponent<AudioSource>();
            sound.Play();
            Destroy(gameObject);
        }
    }
    private IEnumerator die()
    {
        AudioSource sound = GetComponent<AudioSource>();
        sound.Play();
        int rand_n = Random.Range(1, 4);
        if(rand_n == 3){
            Instantiate(coin, transform.position, transform.rotation);
        }
        Instantiate(item, transform.position, transform.rotation);
        yield return new WaitForSeconds(1f);
        Destroy(gameObject);
    }
}
