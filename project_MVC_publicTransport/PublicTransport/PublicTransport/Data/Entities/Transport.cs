using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace PublicTransport.Models
{
    public class Transport
    {
        [Key]
        [Required]
        public Guid transportId { get; set; }
        [Required]
        [Display(Name = "Номер транспорта")]
        public int transportName{ get; set; }
        [Required]
        [Display(Name = "Тип транспорта")]
        public string transportType{ get; set; }
        [Display(Name = "Цена проезда")]
        public int transportPrice{ get; set; }
        
    }
}
