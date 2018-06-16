<?php
namespace Home\Controller;
use Think\Controller;
class IndexController extends Controller {
    public function index(){
		if($_POST['submit']){
			$text=$_POST['text'];
			$pro=explode("<>", $text);
			$cnt = count($pro);
			echo $cnt;
			for($i = 0; $i < $cnt; ++$i) {
				$data=explode("||",$pro[$i]);
				$data[0]=trim($data[0],"（）");
				$data[0]=trim($data[0]);
				// echo count($data);
				// for($j = 0; $j < 7; ++$j) {
				// 	echo $data[$j]."<br>";
				// }
				$mp['description'] = $data[0];
				$mp['answer'] = $data[1];
				// $mp['type'] = "multiple";
				// $mp['type'] = "single";
				$mp['type'] = "trueorfalse";
				$mp['A'] = $data[2]?$data[2]:"";
				$mp['B'] = $data[3]?$data[3]:"";
				$mp['C'] = $data[4]?$data[4]:"";
				$mp['D'] = $data[5]?$data[5]:"";
				$mp['E'] = $data[6]?$data[6]:"";
				$mp['suit_dev']=1;
				$mp['time']=date("Y-m-d H:i:s");
				// var_dump($mp);
				// echo '<br>';
				// D('exam_problem')->add($mp);
			}
	    }
	    $this->display();
    }
}