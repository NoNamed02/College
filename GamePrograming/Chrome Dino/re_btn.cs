using UnityEngine;
using UnityEngine.SceneManagement;

public class re_btn : MonoBehaviour
{
    public void RestartScene()
    {
        // 현재 씬을 다시 로드
        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);
    }
}
