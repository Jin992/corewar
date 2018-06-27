# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    winner_test.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: earteshc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/12 15:57:14 by earteshc          #+#    #+#              #
#    Updated: 2018/05/12 15:57:16 by earteshc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#! /bin/bash
bot=(../cor/ex.cor ../cor/Machine-gun.cor ../cor/MarineKing.cor ../cor/Misaka_Mikoto.cor ../cor/THUNDER.cor ../cor/Varimathras.cor ../cor/Varimathras.cor ../cor/Wall.cor ../cor/casimir.cor ../cor/dubo.cor ../cor/littlepuppy.cor ../cor/sam_2.0.cor ../cor/MarineKing.cor ../cor/Varimathras.cor ../cor/champ.cor ../cor/gedeon.cor ../cor/meowluigi.cor ../cor/terminator.cor ../cor/Gagnant.cor ../cor/Octobre_Rouge_V4.2.cor ../cor/jumper.cor ../cor/maxidef.cor ../cor/toto.cor)

BOTCNT=22
END=$2
TOTALTEST=0
TOTALFAIL=0;
function check_1()
{
  echo "\033[1;34m 1 - player test\033[0m "$END" times"
  for ((i=0; i<$END ; i++));
    do
     bot1=${bot[$(((RANDOM*50%$BOTCNT)))]}
     perl -e 'alarm shift @ARGV; exec @ARGV' 30 ./../corewar ${bot1} > f1
      ./../original/corewar ${bot1}  > f2
      DIFF=$(diff f1 f2) 
     if ["$DIFF" == ""];
       then
         echo "\033[1;32m[OK]\033[0m"${bot1}
         echo "[OK]"${bot1} >> test_res_OK_1
         ((TOTALTEST++))
      else
         echo "\033[1;31m[KO]\033[0m"${bot1}
         echo "[KO]"${bot1} >> test_res_KO_2
         ((TOTALFAIL++))
    fi
    rm f1 f2
  done
}
function check_2()
{
  echo "\033[1;34m 2 - players test\033[0m "$END" times"
  for ((i=0; i<$END ; i++));
    do
     bot1=${bot[$(((RANDOM*50%$BOTCNT)))]}
     bot2=${bot[$(((RANDOM*37%$BOTCNT)))]}
      perl -e 'alarm shift @ARGV; exec @ARGV' 30 ./../corewar  ${bot1} ${bot2}  > f1
      ./../original/corewar ${bot1} ${bot2} > f2
      DIFF=$(diff f1 f2) 
     if ["$DIFF" == ""];
       then
         echo "\033[1;32m[OK]\033[0m"${bot1}" "${bot2}
         echo "[OK]"${bot1}" "${bot2} >> test_res_OK_2
         ((TOTALTEST++))
      else
         echo "\033[1;31m[KO]\033[0m"${bot1}" "${bot2}
         echo "[KO]"${bot1}" "${bot2} >> test_res_KO_2
         ((TOTALFAIL++))
    fi
    rm f1 f2
  done
}

function check_3()
{
  echo "\033[1;34m 3 - players test\033[0m "$END" times"
  for ((i=0; i<$END; i++));
  do
   bot1=${bot[$(((RANDOM*77%$BOTCNT)))]}
   bot2=${bot[$(((RANDOM*37%$BOTCNT)))]}
   bot3=${bot[$(((RANDOM*22%$BOTCNT)))]}
   perl -e 'alarm shift @ARGV; exec @ARGV' 120 ./../corewar  ${bot1} ${bot2} ${bot3} > f1
    ./../original/corewar ${bot1} ${bot2} ${bot3} > f2
    DIFF=$(diff f1 f2 ) 
   if ["$DIFF" == ""]; then
      echo "\033[1;32m[OK]\033[0m"${bot1}" "${bot2}" "${bot3}
      echo "[OK]"${bot1}" "${bot2}" "${bot3} >> test_res_OK_3
      ((TOTALTEST++))
    else
      echo "\033[1;31m[KO]\033[0m"${bot1}" "${bot2}" "${bot3}
      echo "[KO]"${bot1}" "${bot2}" "${bot3} >> test_res_KO_3
      ((TOTALFAIL++))
    fi
    rm f1 f2 
  done
}

function check_4()
{
  echo "\033[1;34m 4 - players test\033[0m "$END" times"
   for ((i=0; i<$END; i++));
  do
   bot1=${bot[$(((RANDOM*50%$BOTCNT)))]}
   bot2=${bot[$(((RANDOM*37%$BOTCNT)))]}
   bot3=${bot[$(((RANDOM*90%$BOTCNT)))]}
   bot4=${bot[$(((RANDOM*55%$BOTCNT)))]}
   perl -e 'alarm shift @ARGV; exec @ARGV' 180 ./../corewar  ${bot1} ${bot2} ${bot3} ${bot4}  > f1
    ./../original/corewar ${bot1} ${bot2} ${bot3} ${bot4}  > f2
    DIFF=$(diff f1 f2) 
   if ["$DIFF" == ""]; then
      echo "\033[1;32m[OK]\033[0m"${bot1}" "${bot2}" "${bot3}" "${bot4}
      echo "[OK]"${bot1}" "${bot2}" "${bot3}" "${bot4} >> test_res_OK_4
      ((TOTALTEST++))
    else
      echo "\033[1;31m[KO]\033[0m"${bot1}" "${bot2}" "${bot3}" "${bot4}
      echo "[KO]"${bot1}" "${bot2}" "${bot3} " "${bot4} >> test_res_KO_4
      ((TOTALFAIL++))
    fi
    rm f1 f2
done
}

if [[ $1 == "2" ]];then
  check_2
elif [[ $1 == "1" ]];then 
  check_1
elif [[ $1 == "3" ]];then
  check_3
elif [[ $1 == "4" ]];then
  check_4
  else
    echo "Wrong argument"
fi

echo "Total test qnt: "${END}" Success tests :"${TOTALTEST} " Fail tests: "${TOTALFAIL}


